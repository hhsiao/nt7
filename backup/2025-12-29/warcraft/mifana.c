// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小飛米[2;37;0m[2;37;0m", ({"xmf"}));        
        set("gender", "女性");                
        set("long", "小飛米[2;37;0m
它是白米飯的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mifana");
        set("owner_name", "白米飯");
        set_temp("owner", "mifana");
        set_temp("owner_name", "白米飯");
        ::setup();
}
