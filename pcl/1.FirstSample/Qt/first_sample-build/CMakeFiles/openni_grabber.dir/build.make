# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample-build

# Include any dependencies generated for this target.
include CMakeFiles/openni_grabber.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/openni_grabber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openni_grabber.dir/flags.make

CMakeFiles/openni_grabber.dir/main.cpp.o: CMakeFiles/openni_grabber.dir/flags.make
CMakeFiles/openni_grabber.dir/main.cpp.o: /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample-build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/openni_grabber.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/openni_grabber.dir/main.cpp.o -c /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample/main.cpp

CMakeFiles/openni_grabber.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openni_grabber.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample/main.cpp > CMakeFiles/openni_grabber.dir/main.cpp.i

CMakeFiles/openni_grabber.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openni_grabber.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample/main.cpp -o CMakeFiles/openni_grabber.dir/main.cpp.s

CMakeFiles/openni_grabber.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/openni_grabber.dir/main.cpp.o.requires

CMakeFiles/openni_grabber.dir/main.cpp.o.provides: CMakeFiles/openni_grabber.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/openni_grabber.dir/build.make CMakeFiles/openni_grabber.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/openni_grabber.dir/main.cpp.o.provides

CMakeFiles/openni_grabber.dir/main.cpp.o.provides.build: CMakeFiles/openni_grabber.dir/main.cpp.o

# Object files for target openni_grabber
openni_grabber_OBJECTS = \
"CMakeFiles/openni_grabber.dir/main.cpp.o"

# External object files for target openni_grabber
openni_grabber_EXTERNAL_OBJECTS =

openni_grabber: CMakeFiles/openni_grabber.dir/main.cpp.o
openni_grabber: /usr/local/lib/libboost_system.so
openni_grabber: /usr/local/lib/libboost_filesystem.so
openni_grabber: /usr/local/lib/libboost_thread.so
openni_grabber: /usr/local/lib/libboost_date_time.so
openni_grabber: /usr/local/lib/libboost_iostreams.so
openni_grabber: /usr/local/lib/libboost_mpi.so
openni_grabber: /usr/local/lib/libboost_serialization.so
openni_grabber: /usr/local/lib/libpcl_common.so
openni_grabber: /usr/lib/libflann_cpp_s.a
openni_grabber: /usr/local/lib/libpcl_kdtree.so
openni_grabber: /usr/local/lib/libpcl_octree.so
openni_grabber: /usr/local/lib/libpcl_search.so
openni_grabber: /usr/local/lib/libpcl_sample_consensus.so
openni_grabber: /usr/local/lib/libpcl_filters.so
openni_grabber: /usr/lib/libOpenNI.so
openni_grabber: /usr/lib/libvtkCommon.so.5.8.0
openni_grabber: /usr/lib/libvtkRendering.so.5.8.0
openni_grabber: /usr/lib/libvtkHybrid.so.5.8.0
openni_grabber: /usr/lib/libvtkCharts.so.5.8.0
openni_grabber: /usr/local/lib/libpcl_io.so
openni_grabber: /usr/local/lib/libpcl_features.so
openni_grabber: /usr/local/lib/libpcl_visualization.so
openni_grabber: /usr/local/lib/libpcl_ml.so
openni_grabber: /usr/local/lib/libpcl_segmentation.so
openni_grabber: /usr/local/lib/libpcl_people.so
openni_grabber: /usr/local/lib/libpcl_keypoints.so
openni_grabber: /usr/lib/libqhull.so
openni_grabber: /usr/local/lib/libpcl_surface.so
openni_grabber: /usr/local/lib/libpcl_registration.so
openni_grabber: /usr/local/lib/libpcl_recognition.so
openni_grabber: /usr/local/lib/libpcl_outofcore.so
openni_grabber: /usr/local/lib/libpcl_stereo.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libGLU.so
openni_grabber: /usr/lib/libGL.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libSM.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libICE.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libX11.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libXext.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libGLEW.so
openni_grabber: /usr/local/lib/libpcl_simulation.so
openni_grabber: /usr/local/lib/libpcl_tracking.so
openni_grabber: /usr/local/lib/libpcl_apps.so
openni_grabber: /usr/local/lib/libpcl_3d_rec_framework.so
openni_grabber: /usr/local/lib/libboost_system.so
openni_grabber: /usr/local/lib/libboost_filesystem.so
openni_grabber: /usr/local/lib/libboost_thread.so
openni_grabber: /usr/local/lib/libboost_date_time.so
openni_grabber: /usr/local/lib/libboost_iostreams.so
openni_grabber: /usr/local/lib/libboost_mpi.so
openni_grabber: /usr/local/lib/libboost_serialization.so
openni_grabber: /usr/lib/libqhull.so
openni_grabber: /usr/lib/libOpenNI.so
openni_grabber: /usr/lib/libflann_cpp_s.a
openni_grabber: /usr/lib/libvtkCommon.so.5.8.0
openni_grabber: /usr/lib/libvtkRendering.so.5.8.0
openni_grabber: /usr/lib/libvtkHybrid.so.5.8.0
openni_grabber: /usr/lib/libvtkCharts.so.5.8.0
openni_grabber: /usr/local/lib/libpcl_common.so
openni_grabber: /usr/local/lib/libpcl_kdtree.so
openni_grabber: /usr/local/lib/libpcl_octree.so
openni_grabber: /usr/local/lib/libpcl_search.so
openni_grabber: /usr/local/lib/libpcl_sample_consensus.so
openni_grabber: /usr/local/lib/libpcl_filters.so
openni_grabber: /usr/local/lib/libpcl_io.so
openni_grabber: /usr/local/lib/libpcl_features.so
openni_grabber: /usr/local/lib/libpcl_visualization.so
openni_grabber: /usr/local/lib/libpcl_ml.so
openni_grabber: /usr/local/lib/libpcl_segmentation.so
openni_grabber: /usr/local/lib/libpcl_people.so
openni_grabber: /usr/local/lib/libpcl_keypoints.so
openni_grabber: /usr/local/lib/libpcl_surface.so
openni_grabber: /usr/local/lib/libpcl_registration.so
openni_grabber: /usr/local/lib/libpcl_recognition.so
openni_grabber: /usr/local/lib/libpcl_outofcore.so
openni_grabber: /usr/local/lib/libpcl_stereo.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libGLU.so
openni_grabber: /usr/lib/libGL.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libSM.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libICE.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libX11.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libXext.so
openni_grabber: /usr/lib/x86_64-linux-gnu/libGLEW.so
openni_grabber: /usr/local/lib/libpcl_simulation.so
openni_grabber: /usr/local/lib/libpcl_tracking.so
openni_grabber: /usr/local/lib/libpcl_apps.so
openni_grabber: /usr/local/lib/libpcl_3d_rec_framework.so
openni_grabber: /usr/lib/libvtkViews.so.5.8.0
openni_grabber: /usr/lib/libvtkInfovis.so.5.8.0
openni_grabber: /usr/lib/libvtkWidgets.so.5.8.0
openni_grabber: /usr/lib/libvtkHybrid.so.5.8.0
openni_grabber: /usr/lib/libvtkParallel.so.5.8.0
openni_grabber: /usr/lib/libvtkVolumeRendering.so.5.8.0
openni_grabber: /usr/lib/libvtkRendering.so.5.8.0
openni_grabber: /usr/lib/libvtkGraphics.so.5.8.0
openni_grabber: /usr/lib/libvtkImaging.so.5.8.0
openni_grabber: /usr/lib/libvtkIO.so.5.8.0
openni_grabber: /usr/lib/libvtkFiltering.so.5.8.0
openni_grabber: /usr/lib/libvtkCommon.so.5.8.0
openni_grabber: /usr/lib/libvtksys.so.5.8.0
openni_grabber: CMakeFiles/openni_grabber.dir/build.make
openni_grabber: CMakeFiles/openni_grabber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable openni_grabber"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openni_grabber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/openni_grabber.dir/build: openni_grabber
.PHONY : CMakeFiles/openni_grabber.dir/build

CMakeFiles/openni_grabber.dir/requires: CMakeFiles/openni_grabber.dir/main.cpp.o.requires
.PHONY : CMakeFiles/openni_grabber.dir/requires

CMakeFiles/openni_grabber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/openni_grabber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/openni_grabber.dir/clean

CMakeFiles/openni_grabber.dir/depend:
	cd /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample-build /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample-build /opt/i-vizon/trunk/pcl/1.FirstSample/Qt/first_sample-build/CMakeFiles/openni_grabber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openni_grabber.dir/depend
