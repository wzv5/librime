//
// Copyright RIME Developers
// Distributed under the BSD License
//
// 2012-04-27 GONG Chen <chen.sst@gmail.com>
//
#ifndef RIME_COMMIT_HISTORY_H_
#define RIME_COMMIT_HISTORY_H_

#include <rime_api.h>
#include <rime/common.h>

namespace rime {

struct CommitRecord {
  string type;
  string text;
  CommitRecord(const string& a_type, const string& a_text)
      : type(a_type), text(a_text) {}
  CommitRecord(int keycode) : type("thru"), text(1, keycode) {}
};

class KeyEvent;
class Composition;

class CommitHistory : public list<CommitRecord> {
 public:
  static const size_t kMaxRecords = 20;
  RIME_DLL void Push(const CommitRecord& record);
  RIME_DLL void Push(const KeyEvent& key_event);
  RIME_DLL void Push(const Composition& composition, const string& input);
  RIME_DLL string repr() const;
  RIME_DLL string latest_text() const;
};

}  // Namespace rime

#endif  // RIME_COMMIT_HISTORY_H_
