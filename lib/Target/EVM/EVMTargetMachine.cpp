//===-- EVMTargetMachine.cpp - Define TargetMachine for EVM -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Implements the info about EVM target spec.
//
//===----------------------------------------------------------------------===//

#include "EVMTargetMachine.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "MCTargetDesc/EVMMCTargetDesc.h"
using namespace llvm;

static std::string computeDataLayout(const Triple &TT) {
   return "E-p:256:256-i256:256-a:0:256-n256-S256";
}

static Reloc::Model getEffectiveRelocModel(const Triple &TT,
                                           Optional<Reloc::Model> RM) {
  if (!RM.hasValue())
    return Reloc::Static;
  return *RM;
}

static CodeModel::Model getEffectiveCodeModel(Optional<CodeModel::Model> CM) {
  if (CM)
    return *CM;
  return CodeModel::Small;
}
/*
 *
 * const Target &T, const Triple &TT, StringRef CPU, StringRef Features,
           const TargetOptions &Options, Optional<Reloc::Model> RM,
           Optional<CodeModel::Model> CM, CodeGenOpt::Level OL, bool JIT
const Target &T, const Triple &TT,
                                       StringRef CPU, StringRef FS,
                                       const TargetOptions &Options,
                                       Optional<Reloc::Model> RM,
                                       Optional<CodeModel::Model> CM,
                                       CodeGenOpt::Level OL, bool JIT
*/
EVMTargetMachine::EVMTargetMachine(const Target &T, const Triple &TT,
                                       StringRef CPU, StringRef FS,
                                       const TargetOptions &Options,
                                       Optional<Reloc::Model> RM,
                                       Optional<CodeModel::Model> CM,
                                       CodeGenOpt::Level OL, bool JIT)
    : LLVMTargetMachine(T, computeDataLayout(TT), TT, CPU, FS, Options,
                        getEffectiveRelocModel(TT, RM),
                        CodeModel::Small, OL) {
  initAsmInfo();
}

TargetPassConfig *EVMTargetMachine::createPassConfig(PassManagerBase &PM) {
    return new TargetPassConfig(static_cast<LLVMTargetMachine&>(*this), PM);
}

bool EVMTargetMachine::addPassesToEmitFile(legacy::PassManagerBase &, raw_pwrite_stream &, raw_pwrite_stream *, TargetMachine::CodeGenFileType, bool, MachineModuleInfo *MMI)
{
    return false;
}

bool EVMTargetMachine::addPassesToEmitMC(legacy::PassManagerBase &, MCContext *&, raw_pwrite_stream &, bool)
{
    return false;
}

extern "C" void LLVMInitializeEVMTarget() {
    RegisterTargetMachine<EVMTargetMachine> X(getTheEVMTarget());
}
