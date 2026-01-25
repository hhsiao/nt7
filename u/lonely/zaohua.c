// zaohua.c 造化紫箐丹

#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }
varargs void autoload(string param, object owner) {
    int amt;

    if (sscanf(param, "%d", amt) == 1)
        set_amount(amt);
}

void setup() {
    set_amount(1);
    ::setup();
}

void create() {
    set_name(HIM "造化紫箐丹" NOR, ({ "zaohua dan", "zaohua", "dan" }) );
    set_weight(300);
    set("long", HIM "一顆紫中泛黃的精緻奇丹，具有著神話般的功效，傳\n"
        "說吃了之後能平增數甲子的功力，乃是練武之人夢寐\n"
        "以求的神丹妙藥。\n" NOR);
    set("base_value", 1000000);
    set("base_weight", 100);
    set("no_sell", 1);
    set("base_unit", "粒");
    set("only_do_effect", 1);
    setup();
}

int do_effect(object me) {
    string mapsk;
    int effect;

    effect = 0;

    if(me->is_busy() ) return notify_fail(BUSY_MESSAGE);
    me->start_busy(2 + random(2));

    if(query("skybook/item/zaohua", me) )
    {
        me->improve_neili(100000);
        addn("skybook/item/zaohua", 1, me);
        message_vision(HIW "$N" HIW "一仰脖，吞下了一顆造化紫箐丹，只見$P"
            HIW "渾身一顫，七竅都冒出白煙來。\n" NOR, me);
    } else
    {
        message_vision(HIW "$N" HIW "一仰脖，吞下了一顆造化紫箐丹，只見$P"
            HIW "渾身一顫，七竅都冒出白煙來。\n" NOR, me);

        addn("drug_addneili", 100000, me);

        mapsk = me->query_skill_mapped("force");
        if (me->can_improve_skill("force"))
            me->improve_skill("force", 1500000);
        if (stringp(mapsk) && me->can_improve_skill(mapsk))
            me->improve_skill(mapsk, 1500000);

        mapsk = me->query_skill_mapped("parry");
        if (me->can_improve_skill("parry"))
            me->improve_skill("parry", 1500000);
        if (stringp(mapsk) && me->can_improve_skill(mapsk))
            me->improve_skill(mapsk, 1500000);

        mapsk = me->query_skill_mapped("dodge");
        if (me->can_improve_skill("dodge"))
            me->improve_skill("dodge", 1500000);
        if (stringp(mapsk) && me->can_improve_skill(mapsk))
            me->improve_skill(mapsk, 1500000);

        me->improve_neili(100000);
    }
    add_amount(-1);
    if(query_amount() < 1 )
        destruct(this_object());
    return 1;
}
