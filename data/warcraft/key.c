// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m赤[1;37m羽[2;37;0m[2;37;0m", ({"jin"}));        
        set("gender", "女性");                
        set("long", "擁有赤色羽毛的不死鳥[2;37;0m
它是夢璃的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "key");
        set("owner_name", "夢璃");
        set_temp("owner", "key");
        set_temp("owner_name", "夢璃");
        ::setup();
}
