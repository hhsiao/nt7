// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m飢餓[1;35m遊戲[2;37;0m[2;37;0m", ({"hunger"}));        
        set("gender", "男性");                
        set("long", "飢餓遊戲[2;37;0m
它是阿多尼斯的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "adonis");
        set("owner_name", "阿多尼斯");
        set_temp("owner", "adonis");
        set_temp("owner_name", "阿多尼斯");
        ::setup();
}
