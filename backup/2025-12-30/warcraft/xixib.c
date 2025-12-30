// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("筆飛翔[2;37;0m[2;37;0m", ({"xixibbb"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是洗筆的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xixib");
        set("owner_name", "洗筆");
        set_temp("owner", "xixib");
        set_temp("owner_name", "洗筆");
        ::setup();
}
