// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m玉字一號丸[2;37;0m[2;37;0m", ({"yqa"}));        
        set("gender", "女性");                
        set("long", "建立看見了我驚愕[2;37;0m
它是西門玉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yuaqing");
        set("owner_name", "西門玉");
        set_temp("owner", "yuaqing");
        set_temp("owner_name", "西門玉");
        ::setup();
}
