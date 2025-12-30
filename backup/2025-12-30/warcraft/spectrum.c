// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("翱翔[2;37;0m[2;37;0m", ({"gaussian"}));        
        set("gender", "男性");                
        set("long", "這是一隻翱翔在天的朱雀[2;37;0m
它是慕容雲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "spectrum");
        set("owner_name", "慕容雲");
        set_temp("owner", "spectrum");
        set_temp("owner_name", "慕容雲");
        ::setup();
}
