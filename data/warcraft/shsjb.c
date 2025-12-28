// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小小鳥[2;37;0m[2;37;0m", ({"xiaoniao"}));        
        set("gender", "男性");                
        set("long", "小小鳥[2;37;0m
它是大道無盡的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "shsjb");
        set("owner_name", "大道無盡");
        set_temp("owner", "shsjb");
        set_temp("owner_name", "大道無盡");
        ::setup();
}
