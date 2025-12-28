// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "111231[2;37;0m
它是極品彈藥的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jipin");
        set("owner_name", "極品彈藥");
        set_temp("owner", "jipin");
        set_temp("owner_name", "極品彈藥");
        ::setup();
}
