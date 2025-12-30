// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哇哇哇[2;37;0m[2;37;0m", ({"wawawa"}));        
        set("gender", "女性");                
        set("long", "一隻朱雀[2;37;0m
它是張佑的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fpga");
        set("owner_name", "張佑");
        set_temp("owner", "fpga");
        set_temp("owner_name", "張佑");
        ::setup();
}
