// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大火雞[2;37;0m[2;37;0m", ({"dahuoji"}));        
        set("gender", "男性");                
        set("long", "一隻不知道什麼種類的大火雞[2;37;0m
它是龍影的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zhaoxinng");
        set("owner_name", "龍影");
        set_temp("owner", "zhaoxinng");
        set_temp("owner_name", "龍影");
        ::setup();
}
