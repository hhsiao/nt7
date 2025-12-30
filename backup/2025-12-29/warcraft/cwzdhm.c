// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuq"}));        
        set("gender", "女性");                
        set("long", "一隻朱雀。[2;37;0m
它是素手鋒芒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cwzdhm");
        set("owner_name", "素手鋒芒");
        set_temp("owner", "cwzdhm");
        set_temp("owner_name", "素手鋒芒");
        ::setup();
}
