// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("風翼天翔[2;37;0m[2;37;0m", ({"apollo"}));        
        set("gender", "女性");                
        set("long", "小飛鳥[2;37;0m
它是艾歐里亞的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ascend");
        set("owner_name", "艾歐里亞");
        set_temp("owner", "ascend");
        set_temp("owner_name", "艾歐里亞");
        ::setup();
}
