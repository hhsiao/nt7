// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("不死鳥[2;37;0m[2;37;0m", ({"hehe"}));        
        set("gender", "女性");                
        set("long", "這是一隻普通的鳥[2;37;0m
它是無言語的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wgf");
        set("owner_name", "無言語");
        set_temp("owner", "wgf");
        set_temp("owner_name", "無言語");
        ::setup();
}
