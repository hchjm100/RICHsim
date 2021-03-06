#ifndef MyDetectorSettings_H
#define MyDetectorSettings_H 1

#include <map>

#include "RadiatorDescription.hh"

#include "G4GDMLParser.hh"
class G4LogicalVolume;

class MyDetectorSettings
{

public:
    MyDetectorSettings();
    ~MyDetectorSettings();

    void ApplyAuxValue(G4GDMLParser *fParser);
    void ApplyAuxValue(const G4GDMLAuxListType *auxInfoList, G4LogicalVolume *vol = NULL);

    //#AuxXML 1. 定义Setting里的用户函数
    void setColor(G4LogicalVolume *vol, G4String value, G4String unit); //<auxiliary auxtype="setColor" auxvalue="kRed" auxunit="0"/> 参考ROOT的色盘
    void setAlpha(G4LogicalVolume *vol, G4String value);                //<auxiliary auxtype="setAlpha" auxvalue="0.5"/>

    void SetFoilThickness(G4LogicalVolume *vol, G4String value, G4String unit); //<auxiliary auxtype="SetFoilThickness" auxvalue="0.006" auxunit="mm"/>
    void SetGasThickness(G4LogicalVolume *vol, G4String value, G4String unit);  //<auxiliary auxtype="SetGasThickness" auxvalue="0.020" auxunit="mm"/>
    void SetFoilNumber(G4LogicalVolume *vol, G4String value); //<auxiliary auxtype="SetFoilNumber" auxvalue="200"/>
    void SetFoilMaterial(G4LogicalVolume *vol, G4String value); //<auxiliary auxtype="SetFoilMaterial" auxvalue="G4_C"/>
    void SetGasMaterial(G4LogicalVolume *vol, G4String value); //<auxiliary auxtype="SetGasMaterial" auxvalue="G4_AIR"/>

    RadiatorDescription* GetRadiatorDescription() { return fRadiatorDescription; }

private:
    RadiatorDescription *fRadiatorDescription = 0;
};

#endif
