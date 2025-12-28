// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大笨鳥[2;37;0m[2;37;0m", ({"hxrds"}));        
        set("gender", "女性");                
        set("long", "一隻笨死的鳥，不過因為是朱雀，所以沒死成。。。汗[2;37;0m
它是黃小蓉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hxr");
        set("owner_name", "黃小蓉");
        set_temp("owner", "hxr");
        set_temp("owner_name", "黃小蓉");
        ::setup();
}
