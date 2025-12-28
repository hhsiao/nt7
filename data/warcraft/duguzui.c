// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m巨雕[2;37;0m[2;37;0m", ({"judiao"}));        
        set("gender", "女性");                
        set("long", "這是一隻火紅的巨雕，傳說它身上有朱雀的靈魂。[2;37;0m
它是獨孤醉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "duguzui");
        set("owner_name", "獨孤醉");
        set_temp("owner", "duguzui");
        set_temp("owner_name", "獨孤醉");
        ::setup();
}
