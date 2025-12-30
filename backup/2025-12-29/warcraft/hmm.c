// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m奈[5m[1;37m落[2;37;0m[2;37;0m", ({"xox"}));        
        set("gender", "女性");                
        set("long", "其視乃明，不食不寢不息，風雨是謁。是燭九陰，是燭龍。[2;37;0m
它是奢比屍的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "hmm");
        set("owner_name", "奢比屍");
        set_temp("owner", "hmm");
        set_temp("owner_name", "奢比屍");
        ::setup();
}
