// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m鯤鵬[2;37;0m[2;37;0m", ({"flying"}));        
        set("gender", "男性");                
        set("long", "北冥有魚,其名為鯤,鯤之大,不知其幾千裡也[2;37;0m
它是不拜天的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "freedom");
        set("owner_name", "不拜天");
        set_temp("owner", "freedom");
        set_temp("owner_name", "不拜天");
        ::setup();
}
