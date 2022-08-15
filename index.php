<!DOCTYPE html>
<html>
<head>
	<title>I-Food | Menu</title>
	<link rel="stylesheet" type="text/css" href="menu.css">
	<script src="menu.js"></script>
</head>
<body>
<div id="warp" >
    <div id="header"  class="">
      <div id="logo__box " class="">
        <img src="https://www.logo.wine/a/logo/Apple_Inc./Apple_Inc.-Logo.wine.svg" alt="" class="logo">
      </div>
      <div  class="headright">
          
          <h3 class="login">Hi, Dear Customer | <span><a class="hiUser text-animation " href="main.html"> Logout</a></span></h3>
      
      </div>
    </div>
  
   <div id="mainMenu" class="">
      <ul class="mainMenu-list ">
        <li><a href="main.html" class="text-animation">Home</a></li>
        <li><a href="../../cms/admin" class="text-animation">CMS</a></li>
      </ul>
    
     <div class="search-box">
       <input type="text" placeholder="search" class="search">
     <button class="search-button">
       <svg xmlns="http://www.w3.org/2000/svg" class="search-icon" viewBox="0 0 20 20" fill="currentColor">
  <path fill-rule="evenodd" d="M8 4a4 4 0 100 8 4 4 0 000-8zM2 8a6 6 0 1110.89 3.476l4.817 4.817a1 1 0 01-1.414 1.414l-4.816-4.816A6 6 0 012 8z" clip-rule="evenodd" />
</svg>
     </button>
     </div>
    </div>
  
  
</div>


<!--   menu -->
  


<section class="section-meals ">
  
		<div class="container grid gird--3-cols margin-bottom-md">
		<div class="container  u-margin-bottom-small heading-grid"> 
<?php include '../updated/PHP/dbconn.php';
include 'includes/classes.php';

  
  $heading = 0;
  $meal = 0;


    // for ($j = 0; $j < count($foods_table); $j++) {
    // 	echo $foods_table[$j]->getCategory;
    // }


    for ($x = 0; $x < count( $categories_table); $x++) {
    	// echo "<div ><h3 class='heading'>{$categories_table[$x][0]}</h3></div></div>";
    	for ($j = 0; $j < count($foods_table); $j++) {
    		if($foods_table[$j]->getCategory() == $categories_table[$x][1]){
    			echo '<div class="meal">
					<img class="meal-img fix-width" src="https://media.istockphoto.com/photos/nasi-lemak-malaysian-cuisine-picture-id526149515?s=612x612">
			<div class="meal-content">
				<div class="meal-tags">
				<p class="tag tag--vegetarian ">Vegatarian</p>
				<p class="tag tag--paleo">Paleo</p>
			    </div>
				<p class="meal-title">'.$food_name.'</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>'.$food_calories.'</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>{$food_nutriscore}</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>'.$food_rate.'</strong> rating (441)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>';
    		}
    	}

    }


    // echo $categories_table[0][1];
    // echo $foods_table[0]->getCategory() ===  $categories_table[][1];

    // print_r($foods_table);
  ?>

			<div ><h3 class="heading">main dish</h3></div></div>
				<div class="meal">
					<img class="meal-img fix-width" src="https://images.unsplash.com/photo-1448043552756-e747b7a2b2b8?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=752&q=80">
			<div class="meal-content">
			
				<p class="tag tag--Pescatarian trans">Pescatarian</p>
			
				<p class="meal-title text-center">LALA</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>650</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>74</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (537)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>


			<div class="meal">
					<img class="meal-img fix-width" src="https://media.istockphoto.com/photos/nasi-lemak-malaysian-cuisine-picture-id526149515?s=612x612">
			<div class="meal-content">
				<div class="meal-tags">
				<p class="tag tag--vegetarian ">Vegatarian</p>
				<p class="tag tag--paleo">Paleo</p>
			    </div>
				<p class="meal-title">Nasi Lemak</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>400</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>92</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (441)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>


			<div class="meal">
					<img class="meal-img fix-width"  src="https://images.unsplash.com/photo-1512621776951-a57141f2eefd?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1170&q=80">
			<div class="meal-content">
				<div class="meal-tags">
				<p class="tag tag--vegan">vegan</p>
				<p class="tag tag--paleo">Paleo</p>
			    </div>
				<p class="meal-title">Avocado Salad</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>400</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>92</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (441)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>
        <div class="container  u-margin-bottom-small heading-grid"> <div ><button class="btn btn--green addItem text-center">ADD ITEM</button> </div>
			
		</div>
			<div class="container  u-margin-bottom-small heading-grid"> <div ><h3 class="heading">Side dish</h3></div></div>
        
        <div class="meal">
					<img class="meal-img fix-width" src="https://images.unsplash.com/photo-1626200419199-391ae4be7a41?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1125&q=80">
			<div class="meal-content">
			
				<p class="tag tag--vegetarian trans">Vegatarian</p>
			
				<p class="meal-title">Borocoli Soup</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>650</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>74</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (537)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>


			<div class="meal">
					<img class="meal-img fix-width" src="https://images.unsplash.com/photo-1547496502-affa22d38842?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=677&q=80">
			<div class="meal-content">
				<div class="meal-tags">
				<p class="tag tag--vegan">vegan</p>
				<p class="tag tag--paleo">Paleo</p>
			    </div>
				<p class="meal-title">Side Salad</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>400</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>92</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (441)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>


			<div class="meal">
					<img class="meal-img fix-width" src="https://images.unsplash.com/photo-1583743089695-4b816a340f82?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1170&q=80">
			<div class="meal-content">
				<div class="meal-tags">
				<p class="tag tag--vegan">vegan</p>
				<p class="tag tag--paleo">Paleo</p>
			    </div>
				<p class="meal-title">Cookies</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>400</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>92</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (441)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>
        <div class="container  u-margin-bottom-small heading-grid"> <div ><button class="btn btn--green addItem">ADD ITEM</button> </div>
			
		</div>
        
			<div class="container  u-margin-bottom-small heading-grid"> <div ><h3 class="heading">beverages </h3></div></div>
        <div class="meal">
					<img class="meal-img fix-width" src="https://images.unsplash.com/photo-1600271886742-f049cd451bba?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=387&q=80">
			<div class="meal-content">
			
				<p class="tag tag--vegetarian trans">Vegatarian</p>
			
				<p class="meal-title">Orange Juice</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>650</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>74</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (537)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>


			<div class="meal">
					<img class="meal-img fix-width" src="https://images.unsplash.com/photo-1557772747-77ffbcf6b117?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=387&q=80">
			<div class="meal-content">
				<div class="meal-tags">
				<p class="tag tag--vegan">vegan</p>
				<p class="tag tag--paleo">Paleo</p>
			    </div>
				<p class="meal-title">Melo Marshmello</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>400</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>92</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (441)</span></li>
					<li class="meal-attribute"></li>
					
				</ul>
				
				</div>
				
			</div>


			<div class="meal">
					<img class="meal-img fix-width" src="https://images.unsplash.com/photo-1617524455170-ca63c7f0d472?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=386&q=80">
			<div class="meal-content">
				<div class="meal-tags">
				<p class="tag tag--vegan">vegan</p>
				<p class="tag tag--paleo">Paleo</p>
			    </div>
				<p class="meal-title">Lemonada</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>400</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>92</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (441)</span></li>
					<li class="meal-attribute"></li>
            
				</ul>
				
				</div>
				
			</div>
        <div class="container  u-margin-bottom-small heading-grid"> <div ><button value="ADD ITEM" class="btn btn--green addItem">ADD ITEM</button> </div>
			
		</div>
		<?php
		if(isset($_POST['submit']))
		{
			if(!$_POST['category'] && !$_POST['name'] && !$_POST['description'] &&!$_POST['price'] ) {
				echo "fill up all fields";
			} else {
				$category = $_POST['category'];
				$name = $_POST['name'];
				$description= $_POST['description'];
				$price = $_POST['price'];

				echo '<div class="meal">
					<img class="meal-img fix-width" src="https://images.unsplash.com/photo-1617524455170-ca63c7f0d472?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=386&q=80">
			<div class="meal-content">
				<div class="meal-tags">
				<p class="tag tag--vegan">vegan</p>
				<p class="tag tag--paleo">Paleo</p>
			    </div>
				<p class="meal-title">'. $name.'</p>
				<ul class="meal-attributes">
					<li class="meal-attribute"><ion-icon class="meal-icon" name="flame"></ion-icon><span><strong>400</strong> calories</span</li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="restaurant-outline"></ion-icon> <span >NutriScore &reg; <strong>92</strong></span> </li>
					<li class="meal-attribute"><ion-icon class="meal-icon" name="star-outline"></ion-icon> <span> <strong>4.9</strong> rating (441)</span></li>
					<li class="meal-attribute"></li>
            
				</ul>
				
				</div>
				
			</div>';

			}
			
		}
		?>
        <form method="post" action="menu.php" class="modal hidden">
        	<div >
      <button class="close-modal">&times;</button>
      <h1>Lets add item 🤔</h1>
              <div class="modal__username">
                <label for="username" class="modal_label modal_label">category</label>
              <input type="text" name="category" class="username checkout__input" placeholder="username">
              </div>
              
              <div class="modal__password">
                
              <label for="username" class="modal_label">name</label><input type="text" name="name" class="password checkout__input" placeholder="password">
              </div>
              <div class="modal__password">
                
              <label for="username" class="modal_label">description</label><input type="text" name="description" class="password checkout__input" placeholder="password">
              </div>
              <div class="modal__password">
                
              <label for="username" class="modal_label">price</label><input type="text" name="price" class="password checkout__input" placeholder="password">
              </div>
              <input type="submit" onclick="valid_function()" value="ADD" tabindex="6" name="submit" class="userNewAccount btn btn--orange" />
              
      
    </div>
    <div class="overlay hidden"></div>   
    
        </form>
         
        
        
        

		
	</section>
<script src="menu.js"></script>
    
</body>
</html>
