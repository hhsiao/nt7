// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m兜[1;33m兜[1;32m貓[2;37;0m[2;37;0m", ({"doudoumao"}));        
        set("gender", "女性");                
        set("long", "一隻可愛的小貓，身上有個小兜兜，裡賣裝滿了各種零食。[2;37;0m
它是刃無缺的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "baleno");
        set("owner_name", "刃無缺");
        set_temp("owner", "baleno");
        set_temp("owner_name", "刃無缺");
        ::setup();
}
