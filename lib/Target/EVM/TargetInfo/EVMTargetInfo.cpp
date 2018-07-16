#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
#include "MCTargetDesc/EVMMCTargetDesc.h"
using namespace llvm;
namespace llvm {
Target &getTheEVMTarget() {
    static Target EVMTarget;
    return EVMTarget;
}
}
extern "C" void LLVMInitializeEVMTargetInfo() {
    RegisterTarget<Triple::evm, /*HasJIT=*/true> X(getTheEVMTarget(), "evm",
                                                   "EVM", "EVM");
}

