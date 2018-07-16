#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
#include "EVMMCTargetDesc.h"

using namespace llvm;
static MCAsmInfo *createEVMMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TheTriple) {
    MCAsmInfo *MAI;
    MAI = new EVMMCStaticInfo();
    return MAI;
}
EVMMCStaticInfo::EVMMCStaticInfo()
{
    IsLittleEndian = false;
    AssemblerDialect = 0;
    CodePointerSize = 256;
    UseDataRegionDirectives = false;
    SupportsDebugInformation = false;
    ExceptionsType = ExceptionHandling::None;
    UseIntegratedAssembler = false;
    HasIdentDirective = false;
}
#define GET_INSTRINFO_MC_DESC
#include "EVMGenInstrInfo.inc"
static MCInstrInfo *createEVMMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitEVMMCInstrInfo(X);
  return X;
}

extern "C" void LLVMInitializeEVMTargetMC() {
    RegisterMCAsmInfoFn X(getTheEVMTarget(), createEVMMCAsmInfo);
    TargetRegistry::RegisterMCInstrInfo(getTheEVMTarget(), createEVMMCInstrInfo);
}
