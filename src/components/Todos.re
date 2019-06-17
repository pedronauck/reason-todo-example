open Utils;
open TodoItem;

[@react.component]
let make = (~todos: list(todo), ~onComplete) => {
  let mapItems =
    List.map(todo =>
      <TodoItem key={string_of_int(todo.id)} todo onComplete />
    );

  <div> {todos |> mapItems |> toArr} </div>;
};
