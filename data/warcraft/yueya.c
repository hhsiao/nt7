// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m圓月[2;37;0m[2;37;0m", ({"yuanyue"}));        
        set("gender", "女性");                
        set("long", "一輪圓月[2;37;0m
它是月牙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yueya");
        set("owner_name", "月牙");
        set_temp("owner", "yueya");
        set_temp("owner_name", "月牙");
        ::setup();
}
