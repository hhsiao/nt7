// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m毀容貓[2;37;0m[2;37;0m", ({"xiaomao"}));        
        set("gender", "男性");                
        set("long", "它是一隻有四個兄弟的半大貓[2;37;0m
它是赤色要塞的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "kakyuren");
        set("owner_name", "赤色要塞");
        set_temp("owner", "kakyuren");
        set_temp("owner_name", "赤色要塞");
        ::setup();
}
