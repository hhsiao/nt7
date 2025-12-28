// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輪迴[1;33m聖獸[2;37;0m[2;37;0m", ({"ldlh"}));        
        set("gender", "男性");                
        set("long", "朱雀一族的強者。[2;37;0m
它是血獄帝君的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xydj");
        set("owner_name", "血獄帝君");
        set_temp("owner", "xydj");
        set_temp("owner_name", "血獄帝君");
        ::setup();
}
