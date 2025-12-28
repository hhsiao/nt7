// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("樹林[2;37;0m[2;37;0m", ({"youziye"}));        
        set("gender", "女性");                
        set("long", "茂盛的樹林[2;37;0m
它是柚子的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "youzi");
        set("owner_name", "柚子");
        set_temp("owner", "youzi");
        set_temp("owner_name", "柚子");
        ::setup();
}
