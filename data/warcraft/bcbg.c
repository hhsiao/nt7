// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m卡哇伊[2;37;0m[2;37;0m", ({"chick"}));        
        set("gender", "男性");                
        set("long", "貴啊[2;37;0m
它是白菜餅乾的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bcbg");
        set("owner_name", "白菜餅乾");
        set_temp("owner", "bcbg");
        set_temp("owner_name", "白菜餅乾");
        ::setup();
}
