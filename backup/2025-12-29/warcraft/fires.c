// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("不亞[2;37;0m[2;37;0m", ({"firesfires"}));        
        set("gender", "男性");                
        set("long", "神秘獸[2;37;0m
它是不亞亞的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fires");
        set("owner_name", "不亞亞");
        set_temp("owner", "fires");
        set_temp("owner_name", "不亞亞");
        ::setup();
}
