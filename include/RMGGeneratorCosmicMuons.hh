// Copyright (C) 2022 Luigi Pertoldi <gipert@pm.me>
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
// details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef _RMG_GENERATOR_COSMIC_MUONS_HH_
#define _RMG_GENERATOR_COSMIC_MUONS_HH_

#include <memory>
#include <string>

#include "RMGVGenerator.hh"

#include "CLHEP/Units/SystemOfUnits.h"
#include "G4GenericMessenger.hh"
#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

class EcoMug;

namespace u = CLHEP;

// TODO: must inherit from RMGVGenerator
class RMGGeneratorCosmicMuons : public RMGVGenerator {

  public:

    enum SkyShape {
      kPlane,
      kSphere
    };

    RMGGeneratorCosmicMuons();
    ~RMGGeneratorCosmicMuons();

    RMGGeneratorCosmicMuons(RMGGeneratorCosmicMuons const&) = delete;
    RMGGeneratorCosmicMuons& operator=(RMGGeneratorCosmicMuons const&) = delete;
    RMGGeneratorCosmicMuons(RMGGeneratorCosmicMuons&&) = delete;
    RMGGeneratorCosmicMuons& operator=(RMGGeneratorCosmicMuons&&) = delete;

    void GeneratePrimariesKinematics(G4Event* event) override;
    void SetParticlePosition(G4ThreeVector vec) override{};

    void BeginOfRunAction(const G4Run*) override;
    inline void EndOfRunAction(const G4Run*) override {}

  private:

    std::unique_ptr<EcoMug> fEcoMug;
    std::unique_ptr<G4ParticleGun> fGun = nullptr;

    std::unique_ptr<G4GenericMessenger> fMessenger = nullptr;
    void DefineCommands();
    void SetSkyShape(std::string shape);

    SkyShape fSkyShape = kSphere;
    float fSkyPlaneSize = -1;
    float fSkyPlaneHeight = 50;

    float fSpherePositionThetaMin = 0 * u::deg;
    float fSpherePositionThetaMax = 90 * u::deg;
    float fSpherePositionPhiMin = 0 * u::deg;
    float fSpherePositionPhiMax = 360 * u::deg;

    float fMomentumMin = 0 * u::GeV;
    float fMomentumMax = 1 * u::TeV;
    float fThetaMin = 0 * u::deg;
    float fThetaMax = 90 * u::deg;
    float fPhiMin = 0 * u::deg;
    float fPhiMax = 360 * u::deg;
};

#endif

// vim: tabstop=2 shiftwidth=2 expandtab
