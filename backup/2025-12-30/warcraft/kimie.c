// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火麒麟[2;37;0m[2;37;0m", ({"fireqilin"}));        
        set("gender", "女性");                
        set("long", "我的魔獸[2;37;0m
它是非極品的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kimie");
        set("owner_name", "非極品");
        set_temp("owner", "kimie");
        set_temp("owner_name", "非極品");
        ::setup();
}
