int dispel() { return 0; }

int update_condition(object me, int duration) {
    if (duration < 1)
    {
        tell_object(me, "官府不再通緝你了！\n");
        CHANNEL_D->do_channel(this_object(), "rumor",
            "因為" + me->name(1) + "一直沒能被" +
            "緝拿歸案，聽說官府已經取消了通緝令。");
        return 0;
    }
    me->apply_condition("killer", duration - 1);
    return 1;
}
