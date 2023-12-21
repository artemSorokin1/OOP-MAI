#pragma once
#include "NPC.h"


class INPCFabric {
protected:
    virtual INPC * createNPC(double x, double y) = 0;
    virtual ~INPCFabric();

};

class BearFabric : public INPCFabric {
public:
    INPC * createNPC(double x, double y) override;

};


class ElfFabric : public INPCFabric {
public:
    INPC * createNPC(double x, double y) override;

};


class OutlawFabric : public INPCFabric {
public:
    INPC * createNPC(double x, double y) override;

};


//class NPCFabric {
//public:
//    template<typename NPCType>
//    static NPCType & createNPC(double x, double y) {
//        return *(new NPCType(x, y));
//    }
//};

