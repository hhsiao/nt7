// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m蒼[1;37m麟[2;37;0m[2;37;0m", ({"arr"}));        
        set("gender", "男性");                
        set("long", "神獸[2;37;0m
它是憶秋年的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "neco");
        set("owner_name", "憶秋年");
        set_temp("owner", "neco");
        set_temp("owner_name", "憶秋年");
        ::setup();
}
