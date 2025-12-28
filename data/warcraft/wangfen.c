// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("愛騎[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "男性");                
        set("long", "愛騎[2;37;0m
它是王芬的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wangfen");
        set("owner_name", "王芬");
        set_temp("owner", "wangfen");
        set_temp("owner_name", "王芬");
        ::setup();
}
