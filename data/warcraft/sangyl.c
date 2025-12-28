// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("炙炎飛鴻[2;37;0m[2;37;0m", ({"yanglin"}));        
        set("gender", "女性");                
        set("long", "炙炎飛鴻[2;37;0m
它是桑楊林的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sangyl");
        set("owner_name", "桑楊林");
        set_temp("owner", "sangyl");
        set_temp("owner_name", "桑楊林");
        ::setup();
}
