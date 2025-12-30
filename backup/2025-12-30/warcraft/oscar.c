// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("貝貝[2;37;0m[2;37;0m", ({"sssss"}));        
        set("gender", "女性");                
        set("long", "小跟班[2;37;0m
它是小馨兒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "oscar");
        set("owner_name", "小馨兒");
        set_temp("owner", "oscar");
        set_temp("owner_name", "小馨兒");
        ::setup();
}
