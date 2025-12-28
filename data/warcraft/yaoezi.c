// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("夭鵝子水麒麟[2;37;0m[2;37;0m", ({"yaoeziqilin"}));        
        set("gender", "女性");                
        set("long", "夭鵝子水麒麟[2;37;0m
它是夭鵝兒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaoezi");
        set("owner_name", "夭鵝兒");
        set_temp("owner", "yaoezi");
        set_temp("owner_name", "夭鵝兒");
        ::setup();
}
