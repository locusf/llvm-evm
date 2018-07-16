#include "llvm/CodeGen/MachineCombinerPattern.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#define GET_INSTRINFO_HEADER
#include "EVMGenInstrInfo.inc"
namespace llvm {
class EVMInstrInfo final: public EVMGenInstrInfo {
    explicit EVMInstrInfo();
}
}
