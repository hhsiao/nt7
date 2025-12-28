// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"luobu"}));        
        set("gender", "女性");                
        set("long", "這是一隻朱雀[2;37;0m
它是哥哥瘋了的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "blke");
        set("owner_name", "哥哥瘋了");
        set_temp("owner", "blke");
        set_temp("owner_name", "哥哥瘋了");
        ::setup();
}
