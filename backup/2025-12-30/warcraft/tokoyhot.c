// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m女優[2;37;0m[2;37;0m", ({"actress"}));        
        set("gender", "女性");                
        set("long", "這是一個渾身赤裸的av女優，看起來面上堆滿疲倦。[2;37;0m
它是東京熱的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tokoyhot");
        set("owner_name", "東京熱");
        set_temp("owner", "tokoyhot");
        set_temp("owner_name", "東京熱");
        ::setup();
}
