// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("東方不敗[2;37;0m[2;37;0m", ({"dfbb"}));        
        set("gender", "男性");                
        set("long", "help nick[2;37;0m
它是喂小飽的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wxb");
        set("owner_name", "喂小飽");
        set_temp("owner", "wxb");
        set_temp("owner_name", "喂小飽");
        ::setup();
}
