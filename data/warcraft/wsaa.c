// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小豬豬[2;37;0m[2;37;0m", ({"xzhu"}));        
        set("gender", "男性");                
        set("long", "@@@@[2;37;0m
它是小豬班納的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wsaa");
        set("owner_name", "小豬班納");
        set_temp("owner", "wsaa");
        set_temp("owner_name", "小豬班納");
        ::setup();
}
