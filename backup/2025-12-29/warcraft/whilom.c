// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m流沙[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "碧雲天共楚宮遙。夢魂慣得無拘檢，又踏楊花過謝橋。[2;37;0m
它是東逝水的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "whilom");
        set("owner_name", "東逝水");
        set_temp("owner", "whilom");
        set_temp("owner_name", "東逝水");
        ::setup();
}
