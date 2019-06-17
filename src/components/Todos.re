open Utils;
open TodoItem;

[@react.component]
let make = (~todos: list(todo), ~onComplete) => {
  let items =
    List.map(
      todo => <TodoItem todo key={string_of_int(todo.id)} onComplete />,
      todos,
    );

  <div> {ReasonReact.array(Array.of_list(items))} </div>;
};
