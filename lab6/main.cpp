#include "lib/Visitor.h"
#include "lib/NPCFabric.h"

enum class Type {
    b = 1,
    e,
    o
};

int main() {

    BearVisitor bvis;
    ElfVisitor evis;
    OutlawVisitor ovis;

    BearFabric bf;
    INPC * bear = bf.createNPC(1, 1);
    ElfFabric ef;
    INPC * elf = ef.createNPC(2, 2);
    OutlawFabric of;
    INPC * outlaw = of.createNPC(0, 0);
    std::vector<INPC*> array;
    array.emplace_back(bear);
    array.emplace_back(elf);
    array.emplace_back(outlaw);

    std::cout << bear->isClose(elf, 1.5) << '\n';
    //        defender    attacker


    bool suc = elf->accept(bvis);


    std::cout << suc << '\n';

    delete bear;
    delete elf;
    delete outlaw;

    return 0;

}