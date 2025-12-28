// This program is a part of NT MudLIB 
 
#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name(HBGRN "刑天腰帶" NOR, ({ "xingtian waist", "waist" }));
        set_weight(500);
        /*if (clonep())
                set_default_object(__FILE__);
        else*/
        {
                set("unit", "柄");
                set("long", HIY "這便是刑天曾經使用的腰帶，遍體血光沖天。\n"
                            HIY + name() + HIY "的等級：上古神品  LV10\n" NOR);
                set("value", 3000); 
                set("no_sell", "這樣東西不能賣。\n");
                set("material", "tian jing");
                set("no_pawn", 1);
                set("no_store", 1); // 不能用幹降符文upd
                set("no_save", 1); // quit不保存
                set("armor_prop/armor", 10000);
        }     

        set("mod_mark", "A2041");
        set("mod_level", "M2030");
        set("mod_name", HBRED "刑天套裝" NOR);

        set("quality_level", 3);
        
        setup();
}

void start_borrowing(int time) 
{
        remove_call_out("return_to_back"); 
        call_out("return_to_back", time); 
} 

void return_to_back() 
{ 
        object me; 

        me = environment(); 
        if( !objectp(me) ) 
                return;

        while( objectp(environment(me)) && !playerp(me) ) 
                me = environment(me); 
        
        if( playerp(me) ) 
        { 
                if( me->is_fighting() ) 
                { 
                        call_out("return_to_back", 1); 
                        return; 
                } 

                tell_object(me, HIR"\n一條人影從你眼前一閃而過：" +
                            "“時間已到，老夫取回" NOR + name() + HIR
                            "，就此謝過，咱們後會有期！”\n\n"NOR);
        } else 
        { 
                message("vision", "忽然一個人走了過來，撿起"+name()+"，嘆了口氣，搖搖頭走了。\n", me); 
        } 

        destruct(this_object());
}

int query_autoload() { return 0; }
