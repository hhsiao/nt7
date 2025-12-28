// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m轟炸機[2;37;0m[2;37;0m", ({"hzj"}));        
        set("gender", "男性");                
        set("long", "金色轟炸機[2;37;0m
它是段了麼的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ljjd");
        set("owner_name", "段了麼");
        set_temp("owner", "ljjd");
        set_temp("owner_name", "段了麼");
        ::setup();
}
