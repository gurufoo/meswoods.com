(function ($) {

 Drupal.behaviors.rpgnpcnode = {
attach: function (context) {
console.log('still calling');

$('.page-node-add .form-type-checkboxes .deselectall')
.click(function() {
  $(this)
    .parent()
    .next()
    .find('input[type="checkbox"]')
    .removeAttr('checked');
  });


$('.page-node-add .form-type-checkboxes .selectall')
.click(function() {
  $(this)
    .parent()
    .next()
    .find('input[type="checkbox"]')
    .attr('checked', true);
  });

}



};



})(jQuery);

