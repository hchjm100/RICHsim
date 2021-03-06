//*********************************************
//  This is auto generated by G4gen 0.6
//                                  author:Qian

#include "MyDetectorSettings.hh"

#include "G4NistManager.hh"
#include "G4GDMLAuxStructType.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4Color.hh"
#include "G4UnitsTable.hh"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#include "TROOT.h"
#include "TColor.h"
#pragma GCC diagnostic pop

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyDetectorSettings::MyDetectorSettings()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

MyDetectorSettings::~MyDetectorSettings()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyDetectorSettings::ApplyAuxValue(G4GDMLParser *fParser)
{
    //apply auxvalue to each logical volume
    const G4LogicalVolumeStore *lvs = G4LogicalVolumeStore::GetInstance();
    std::vector<G4LogicalVolume *>::const_iterator lvciter;
    for (lvciter = lvs->begin(); lvciter != lvs->end(); lvciter++)
    {
        G4GDMLAuxListType auxInfo = fParser->GetVolumeAuxiliaryInformation(*lvciter);

        if (auxInfo.size() > 0)
            G4cout << "Auxiliary Information is found for Logical Volume :  "
                   << (*lvciter)->GetName() << G4endl;

        ApplyAuxValue(&auxInfo, (*lvciter));
    }

    //apply global auxvalues
    G4cout << "\nApply global auxiliary settings:" << G4endl;
    ApplyAuxValue(fParser->GetAuxList());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void MyDetectorSettings::ApplyAuxValue(const G4GDMLAuxListType *auxInfoList, G4LogicalVolume *vol)
{
    for (std::vector<G4GDMLAuxStructType>::const_iterator
             iaux = auxInfoList->begin();
         iaux != auxInfoList->end(); iaux++)
    {
        G4String type = iaux->type;
        G4String value = iaux->value;
        G4String unit = iaux->unit;

        G4cout << " | " << type << " : " << value << " " << unit << G4endl;

        //#AuxXML 3. Setting里根据type分发函数
        if (type == "setColor")
            setColor(vol, value, unit);
        if (type == "setAlpha")
            setAlpha(vol, value);
        
        if (type == "setTRD_FoilThickness")
            setTRD_FoilThickness(vol, value, unit);
        if (type == "setTRD_GasThickness")
            setTRD_GasThickness(vol, value, unit);
        if (type == "setTRD_FoilMaterial")
            setTRD_FoilMaterial(vol, value);
        if (type == "setTRD_GasMaterial")
            setTRD_GasMaterial(vol, value);
        if (type == "setTRD_FoilNumber")
            setTRD_FoilNumber(vol, value);

        if (iaux->auxList)
            ApplyAuxValue(iaux->auxList, vol);
    }
    return;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//#AuxXML 4. Setting里实现用户函数
void MyDetectorSettings::setColor(G4LogicalVolume *vol, G4String value, G4String unit)
{
    if (vol == NULL)
        return;
    TColor *color;
    int cid = kRed;

    //TCanvas c1; [View]->[Color]查看root预定义的色盘
    if (value == "kRed" || value == "red")
        cid = kRed;
    if (value == "kPink" || value == "pink")
        cid = kPink;
    if (value == "kMagenta" || value == "magenta")
        cid = kMagenta;
    if (value == "kViolet" || value == "violet")
        cid = kViolet;
    if (value == "kBlue" || value == "blue")
        cid = kBlue;
    if (value == "kAzure" || value == "azure")
        cid = kAzure;
    if (value == "kCyan" || value == "cyan")
        cid = kCyan;
    if (value == "kTeal" || value == "teal")
        cid = kTeal;
    if (value == "kGreen" || value == "green")
        cid = kGreen;
    if (value == "kSpring" || value == "spring")
        cid = kSpring;
    if (value == "kYellow" || value == "yellow")
        cid = kYellow;
    if (value == "kOrange" || value == "orange")
        cid = kOrange;
    if (value == "kGray" || value == "gray")
        cid = kGray;
    if (value == "kWhite" || value == "white")
        cid = kWhite;
    if (value == "kBlack" || value == "black")
        cid = kBlack;

    color = gROOT->GetColor(cid + atoi(unit));

    if (color == NULL)
        return;

    G4VisAttributes *attrPtr = new G4VisAttributes(G4Color(color->GetRed(), color->GetGreen(), color->GetBlue(), 0.8));
    vol->SetVisAttributes(attrPtr);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void MyDetectorSettings::setAlpha(G4LogicalVolume *vol, G4String value)
{
    if (vol == NULL)
        return;

    const G4VisAttributes *attrPtr = vol->GetVisAttributes();
    if (attrPtr == NULL)
        return;

    G4Colour color = attrPtr->GetColor();
    vol->SetVisAttributes(new G4VisAttributes(G4Color(color.GetRed(), color.GetGreen(), color.GetBlue(), atof(value))));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void MyDetectorSettings::setTRD_FoilThickness(G4LogicalVolume *vol, G4String value, G4String unit)
{
    if (fRadiatorDescription == NULL)
        fRadiatorDescription = new RadiatorDescription();
    fRadiatorDescription->fFoilThickness = atof(value) * G4UnitDefinition::GetValueOf(unit);
    fRadiatorDescription->fLogicalVolume = vol;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void MyDetectorSettings::setTRD_GasThickness(G4LogicalVolume *vol, G4String value, G4String unit)
{
    if (fRadiatorDescription == NULL)
        fRadiatorDescription = new RadiatorDescription();
    fRadiatorDescription->fGasThickness = atof(value) * G4UnitDefinition::GetValueOf(unit);
    fRadiatorDescription->fLogicalVolume = vol;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void MyDetectorSettings::setTRD_FoilMaterial(G4LogicalVolume *vol, G4String value)
{
    if (fRadiatorDescription == NULL)
        fRadiatorDescription = new RadiatorDescription();
    fRadiatorDescription->fFoilMaterial = G4NistManager::Instance()->FindOrBuildMaterial(value);
    fRadiatorDescription->fLogicalVolume = vol;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void MyDetectorSettings::setTRD_GasMaterial(G4LogicalVolume *vol, G4String value)
{
    if (fRadiatorDescription == NULL)
        fRadiatorDescription = new RadiatorDescription();
    fRadiatorDescription->fGasMaterial = G4NistManager::Instance()->FindOrBuildMaterial(value);
    fRadiatorDescription->fLogicalVolume = vol;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
void MyDetectorSettings::setTRD_FoilNumber(G4LogicalVolume *vol, G4String value)
{
    if (fRadiatorDescription == NULL)
        fRadiatorDescription = new RadiatorDescription();
    fRadiatorDescription->fFoilNumber = atof(value);
    fRadiatorDescription->fLogicalVolume = vol;
}