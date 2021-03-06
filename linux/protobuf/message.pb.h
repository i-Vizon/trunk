// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef PROTOBUF_message_2eproto__INCLUDED
#define PROTOBUF_message_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_message_2eproto();
void protobuf_AssignDesc_message_2eproto();
void protobuf_ShutdownFile_message_2eproto();

class log_packet;

// ===================================================================

class log_packet : public ::google::protobuf::Message {
 public:
  log_packet();
  virtual ~log_packet();

  log_packet(const log_packet& from);

  inline log_packet& operator=(const log_packet& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const log_packet& default_instance();

  void Swap(log_packet* other);

  // implements Message ----------------------------------------------

  log_packet* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const log_packet& from);
  void MergeFrom(const log_packet& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required fixed64 log_time = 1;
  inline bool has_log_time() const;
  inline void clear_log_time();
  static const int kLogTimeFieldNumber = 1;
  inline ::google::protobuf::uint64 log_time() const;
  inline void set_log_time(::google::protobuf::uint64 value);

  // required fixed32 log_micro_sec = 2;
  inline bool has_log_micro_sec() const;
  inline void clear_log_micro_sec();
  static const int kLogMicroSecFieldNumber = 2;
  inline ::google::protobuf::uint32 log_micro_sec() const;
  inline void set_log_micro_sec(::google::protobuf::uint32 value);

  // required fixed32 sequence_no = 3;
  inline bool has_sequence_no() const;
  inline void clear_sequence_no();
  static const int kSequenceNoFieldNumber = 3;
  inline ::google::protobuf::uint32 sequence_no() const;
  inline void set_sequence_no(::google::protobuf::uint32 value);

  // required fixed32 shm_app_id = 4;
  inline bool has_shm_app_id() const;
  inline void clear_shm_app_id();
  static const int kShmAppIdFieldNumber = 4;
  inline ::google::protobuf::uint32 shm_app_id() const;
  inline void set_shm_app_id(::google::protobuf::uint32 value);

  // required string packet_id = 5;
  inline bool has_packet_id() const;
  inline void clear_packet_id();
  static const int kPacketIdFieldNumber = 5;
  inline const ::std::string& packet_id() const;
  inline void set_packet_id(const ::std::string& value);
  inline void set_packet_id(const char* value);
  inline void set_packet_id(const char* value, size_t size);
  inline ::std::string* mutable_packet_id();
  inline ::std::string* release_packet_id();
  inline void set_allocated_packet_id(::std::string* packet_id);

  // required string log_level = 6;
  inline bool has_log_level() const;
  inline void clear_log_level();
  static const int kLogLevelFieldNumber = 6;
  inline const ::std::string& log_level() const;
  inline void set_log_level(const ::std::string& value);
  inline void set_log_level(const char* value);
  inline void set_log_level(const char* value, size_t size);
  inline ::std::string* mutable_log_level();
  inline ::std::string* release_log_level();
  inline void set_allocated_log_level(::std::string* log_level);

  // required string log_msg = 7;
  inline bool has_log_msg() const;
  inline void clear_log_msg();
  static const int kLogMsgFieldNumber = 7;
  inline const ::std::string& log_msg() const;
  inline void set_log_msg(const ::std::string& value);
  inline void set_log_msg(const char* value);
  inline void set_log_msg(const char* value, size_t size);
  inline ::std::string* mutable_log_msg();
  inline ::std::string* release_log_msg();
  inline void set_allocated_log_msg(::std::string* log_msg);

  // @@protoc_insertion_point(class_scope:log_packet)
 private:
  inline void set_has_log_time();
  inline void clear_has_log_time();
  inline void set_has_log_micro_sec();
  inline void clear_has_log_micro_sec();
  inline void set_has_sequence_no();
  inline void clear_has_sequence_no();
  inline void set_has_shm_app_id();
  inline void clear_has_shm_app_id();
  inline void set_has_packet_id();
  inline void clear_has_packet_id();
  inline void set_has_log_level();
  inline void clear_has_log_level();
  inline void set_has_log_msg();
  inline void clear_has_log_msg();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint64 log_time_;
  ::google::protobuf::uint32 log_micro_sec_;
  ::google::protobuf::uint32 sequence_no_;
  ::std::string* packet_id_;
  ::std::string* log_level_;
  ::std::string* log_msg_;
  ::google::protobuf::uint32 shm_app_id_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(7 + 31) / 32];

  friend void  protobuf_AddDesc_message_2eproto();
  friend void protobuf_AssignDesc_message_2eproto();
  friend void protobuf_ShutdownFile_message_2eproto();

  void InitAsDefaultInstance();
  static log_packet* default_instance_;
};
// ===================================================================


// ===================================================================

// log_packet

// required fixed64 log_time = 1;
inline bool log_packet::has_log_time() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void log_packet::set_has_log_time() {
  _has_bits_[0] |= 0x00000001u;
}
inline void log_packet::clear_has_log_time() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void log_packet::clear_log_time() {
  log_time_ = GOOGLE_ULONGLONG(0);
  clear_has_log_time();
}
inline ::google::protobuf::uint64 log_packet::log_time() const {
  return log_time_;
}
inline void log_packet::set_log_time(::google::protobuf::uint64 value) {
  set_has_log_time();
  log_time_ = value;
}

// required fixed32 log_micro_sec = 2;
inline bool log_packet::has_log_micro_sec() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void log_packet::set_has_log_micro_sec() {
  _has_bits_[0] |= 0x00000002u;
}
inline void log_packet::clear_has_log_micro_sec() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void log_packet::clear_log_micro_sec() {
  log_micro_sec_ = 0u;
  clear_has_log_micro_sec();
}
inline ::google::protobuf::uint32 log_packet::log_micro_sec() const {
  return log_micro_sec_;
}
inline void log_packet::set_log_micro_sec(::google::protobuf::uint32 value) {
  set_has_log_micro_sec();
  log_micro_sec_ = value;
}

// required fixed32 sequence_no = 3;
inline bool log_packet::has_sequence_no() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void log_packet::set_has_sequence_no() {
  _has_bits_[0] |= 0x00000004u;
}
inline void log_packet::clear_has_sequence_no() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void log_packet::clear_sequence_no() {
  sequence_no_ = 0u;
  clear_has_sequence_no();
}
inline ::google::protobuf::uint32 log_packet::sequence_no() const {
  return sequence_no_;
}
inline void log_packet::set_sequence_no(::google::protobuf::uint32 value) {
  set_has_sequence_no();
  sequence_no_ = value;
}

// required fixed32 shm_app_id = 4;
inline bool log_packet::has_shm_app_id() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void log_packet::set_has_shm_app_id() {
  _has_bits_[0] |= 0x00000008u;
}
inline void log_packet::clear_has_shm_app_id() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void log_packet::clear_shm_app_id() {
  shm_app_id_ = 0u;
  clear_has_shm_app_id();
}
inline ::google::protobuf::uint32 log_packet::shm_app_id() const {
  return shm_app_id_;
}
inline void log_packet::set_shm_app_id(::google::protobuf::uint32 value) {
  set_has_shm_app_id();
  shm_app_id_ = value;
}

// required string packet_id = 5;
inline bool log_packet::has_packet_id() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void log_packet::set_has_packet_id() {
  _has_bits_[0] |= 0x00000010u;
}
inline void log_packet::clear_has_packet_id() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void log_packet::clear_packet_id() {
  if (packet_id_ != &::google::protobuf::internal::kEmptyString) {
    packet_id_->clear();
  }
  clear_has_packet_id();
}
inline const ::std::string& log_packet::packet_id() const {
  return *packet_id_;
}
inline void log_packet::set_packet_id(const ::std::string& value) {
  set_has_packet_id();
  if (packet_id_ == &::google::protobuf::internal::kEmptyString) {
    packet_id_ = new ::std::string;
  }
  packet_id_->assign(value);
}
inline void log_packet::set_packet_id(const char* value) {
  set_has_packet_id();
  if (packet_id_ == &::google::protobuf::internal::kEmptyString) {
    packet_id_ = new ::std::string;
  }
  packet_id_->assign(value);
}
inline void log_packet::set_packet_id(const char* value, size_t size) {
  set_has_packet_id();
  if (packet_id_ == &::google::protobuf::internal::kEmptyString) {
    packet_id_ = new ::std::string;
  }
  packet_id_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* log_packet::mutable_packet_id() {
  set_has_packet_id();
  if (packet_id_ == &::google::protobuf::internal::kEmptyString) {
    packet_id_ = new ::std::string;
  }
  return packet_id_;
}
inline ::std::string* log_packet::release_packet_id() {
  clear_has_packet_id();
  if (packet_id_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = packet_id_;
    packet_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void log_packet::set_allocated_packet_id(::std::string* packet_id) {
  if (packet_id_ != &::google::protobuf::internal::kEmptyString) {
    delete packet_id_;
  }
  if (packet_id) {
    set_has_packet_id();
    packet_id_ = packet_id;
  } else {
    clear_has_packet_id();
    packet_id_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string log_level = 6;
inline bool log_packet::has_log_level() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void log_packet::set_has_log_level() {
  _has_bits_[0] |= 0x00000020u;
}
inline void log_packet::clear_has_log_level() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void log_packet::clear_log_level() {
  if (log_level_ != &::google::protobuf::internal::kEmptyString) {
    log_level_->clear();
  }
  clear_has_log_level();
}
inline const ::std::string& log_packet::log_level() const {
  return *log_level_;
}
inline void log_packet::set_log_level(const ::std::string& value) {
  set_has_log_level();
  if (log_level_ == &::google::protobuf::internal::kEmptyString) {
    log_level_ = new ::std::string;
  }
  log_level_->assign(value);
}
inline void log_packet::set_log_level(const char* value) {
  set_has_log_level();
  if (log_level_ == &::google::protobuf::internal::kEmptyString) {
    log_level_ = new ::std::string;
  }
  log_level_->assign(value);
}
inline void log_packet::set_log_level(const char* value, size_t size) {
  set_has_log_level();
  if (log_level_ == &::google::protobuf::internal::kEmptyString) {
    log_level_ = new ::std::string;
  }
  log_level_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* log_packet::mutable_log_level() {
  set_has_log_level();
  if (log_level_ == &::google::protobuf::internal::kEmptyString) {
    log_level_ = new ::std::string;
  }
  return log_level_;
}
inline ::std::string* log_packet::release_log_level() {
  clear_has_log_level();
  if (log_level_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = log_level_;
    log_level_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void log_packet::set_allocated_log_level(::std::string* log_level) {
  if (log_level_ != &::google::protobuf::internal::kEmptyString) {
    delete log_level_;
  }
  if (log_level) {
    set_has_log_level();
    log_level_ = log_level;
  } else {
    clear_has_log_level();
    log_level_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string log_msg = 7;
inline bool log_packet::has_log_msg() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void log_packet::set_has_log_msg() {
  _has_bits_[0] |= 0x00000040u;
}
inline void log_packet::clear_has_log_msg() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void log_packet::clear_log_msg() {
  if (log_msg_ != &::google::protobuf::internal::kEmptyString) {
    log_msg_->clear();
  }
  clear_has_log_msg();
}
inline const ::std::string& log_packet::log_msg() const {
  return *log_msg_;
}
inline void log_packet::set_log_msg(const ::std::string& value) {
  set_has_log_msg();
  if (log_msg_ == &::google::protobuf::internal::kEmptyString) {
    log_msg_ = new ::std::string;
  }
  log_msg_->assign(value);
}
inline void log_packet::set_log_msg(const char* value) {
  set_has_log_msg();
  if (log_msg_ == &::google::protobuf::internal::kEmptyString) {
    log_msg_ = new ::std::string;
  }
  log_msg_->assign(value);
}
inline void log_packet::set_log_msg(const char* value, size_t size) {
  set_has_log_msg();
  if (log_msg_ == &::google::protobuf::internal::kEmptyString) {
    log_msg_ = new ::std::string;
  }
  log_msg_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* log_packet::mutable_log_msg() {
  set_has_log_msg();
  if (log_msg_ == &::google::protobuf::internal::kEmptyString) {
    log_msg_ = new ::std::string;
  }
  return log_msg_;
}
inline ::std::string* log_packet::release_log_msg() {
  clear_has_log_msg();
  if (log_msg_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = log_msg_;
    log_msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void log_packet::set_allocated_log_msg(::std::string* log_msg) {
  if (log_msg_ != &::google::protobuf::internal::kEmptyString) {
    delete log_msg_;
  }
  if (log_msg) {
    set_has_log_msg();
    log_msg_ = log_msg;
  } else {
    clear_has_log_msg();
    log_msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_message_2eproto__INCLUDED
