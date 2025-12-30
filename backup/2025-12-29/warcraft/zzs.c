// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小雞[2;37;0m[2;37;0m", ({"zzss"}));        
        set("gender", "男性");                
        set("long", "這是一隻變異的小小鳥[2;37;0m
它是小強的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zzs");
        set("owner_name", "小強");
        set_temp("owner", "zzs");
        set_temp("owner_name", "小強");
        ::setup();
}
