//char16 A vector of 16 eight bit signed integer values
__kernel
void string_search(__global char* text_file, char16 pattern,
int chars_per_item, __global int* global_result)
{
    char16 text_buffer, check_vector;
    __local int local_result[4];

    //Initialize local_result
    local_result[0] = 0;
    local_result[1] = 0;
    local_result[2] = 0;
    local_result[3] = 0;

    barrier(CLK_GLOBAL_MEM_FENCE);

    //Get starting address of text buffer for each work item to
    //process
    int item_offset = get_global_id(0) * chars_per_item;

    for(int i=0; i < item_offset + chars_per_item; i++)
    {
    /*gentypen vloadn(size_t offset,const global/local/constant/private gentype *p)*/
    text_buffer = vload16(0, text_file + i);

        check_vector = text_buffer == pattern;

        /* Check for 'that' */
        if(all(check_vector.s0123))
        atomic_inc(local_result);

          /* Check for 'with' */
          if(all(check_vector.s4567))
          atomic_inc(local_result + 1);

          /* Check for 'have' */
          if(all(check_vector.s89AB))
          atomic_inc(local_result + 2);

          /* Check for 'from' */
          if(all(check_vector.sCDEF))
          atomic_inc(local_result + 3);
          }
          barrier(CLK_GLOBAL_MEM_FENCE);
          if(get_global_id(0) == 0)
          {
              atomic_add(global_result, local_result[0]);
              atomic_add(global_result + 1, local_result[1]);
              atomic_add(global_result + 2, local_result[2]);
              atomic_add(global_result + 3, local_result[3]);
          }


}
